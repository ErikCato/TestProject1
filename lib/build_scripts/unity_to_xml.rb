#!/usr/bin/ruby
#
# unity_to_junit.rb
#
require 'fileutils'
require 'set'
class UnityToJUnit
  include FileUtils::Verbose
  attr_reader :report, :total_tests, :failures, :ignored
  
  def initialize
    @report = ''
    @output = nil
    @unit_name = ''
  end
  
  def run   
    # Clean up result file names
    results = @targets.map {|target| target.gsub(/\\/,"/")}
    f = File.new("result.xml", "w") 
    results.each do |result_file|
      lines = File.readlines(result_file).map { |line| line.chomp }
      if lines.length == 0
        raise "Empty test result file: #{result_file}"
      else
        result_output = get_details(result_file, lines)
        tests,failures,ignored = parse_test_summary(lines)    
        result_output[:counts][:total] = tests
        result_output[:counts][:failed] = failures
        result_output[:counts][:ignored] = ignored
        result_output[:counts][:passed] = (result_output[:counts][:total] - result_output[:counts][:failed] - result_output[:counts][:ignored])
      end
      #use line[0] from the test output to get the test_file path and name
      test_file_str = lines[0].gsub("\\","/")
      test_file_str = test_file_str.split(":")
      test_file = test_file_str[0] + ':' + test_file_str[1]
      result_output[:source][:path] = File.dirname(test_file)
      result_output[:source][:file] = File.basename(test_file)
      # save result_output
      @unit_name = File.basename(test_file, ".*")
      @output = result_output   
    end
    write_results(@output, f)
    f.close
  end
  
  def set_targets(target_array)
    @targets = target_array
  end
  
  def set_root_path(path)
    @root = path
  end
  def usage(err_msg=nil)
    puts "\nERROR: "
    puts err_msg if err_msg
    puts "\nUsage: unity_to_junit.rb result_file_directoy/ root_path/"
    puts "     result_file_directory - The location of your relults files." 
    puts "                             Defaults to current directory if not specified."
    puts "                             Should end in / if specified."
    puts "     root_path (not tested) - Helpful for producing more verbose output if using relative paths."
    exit 1
  end
  
  protected
  def get_details(result_file, lines)
    results = get_results_structure  
    lines.each do |line|
      line = line.gsub("\\","/")
      line = line.split("/").last
      src_file,src_line,test_name,status,msg = line.split(/:/)
      line_out = ((@root and (@root != 0)) ? "#{@root}#{line}" : line ).gsub(/\//, "\\")
      case(status)
        when 'IGNORE' then results[:ignores] << {:test => test_name, :line => src_line, :message => msg}
        when 'FAIL'   then results[:failures] << {:test => test_name, :line => src_line, :message => msg}
        when 'PASS'   then results[:successes] << {:test => test_name, :line => src_line, :message => msg}
      end
    end
    return results
  end
  
  def parse_test_summary(summary)
    if summary.find { |v| v =~ /(\d+) Tests (\d+) Failures (\d+) Ignored/ }
      [$1.to_i,$2.to_i,$3.to_i]
    else
      raise "Couldn't parse test results: #{summary}"
    end
  end
  def here; File.expand_path(File.dirname(__FILE__)); end
  
  private
  
  def get_results_structure
    return {
      :source    => {:path => '', :file => ''},
      :successes => [],
      :failures  => [],
      :ignores   => [],
      :counts    => {:total => 0, :passed => 0, :failed => 0, :ignored  => 0},
      :stdout    => [],
    } 
  end
  
  def write_results( results, stream )
    write_header( results[:counts], stream )
    write_failures( results, stream )
    write_tests( results, stream )
    write_ignored( results, stream )
    write_footer( stream )
  end
  def write_header( counts, stream )
    stream.puts "<?xml version='1.0' encoding='utf-8' ?>"
    stream.puts "<testsuite errors=\"0\" skipped=\"#{counts[:ignored]}\" failures=\"#{counts[:failed]}\" tests=\"#{counts[:total]}\" name=\"unity\">"
  end
  def write_failures( results, stream )
    result = results[:failures]
    result.each do |item|
      filename = File.join(results[:source][:path], File.basename(results[:source][:file], '.*'))
      stream.puts "\t<testcase classname=\"#{@unit_name}\" name=\"#{item[:test]}\" time=\"0\">"
      stream.puts "\t\t<failure message=\"#{item[:message]}\" type=\"Assertion\"/>"
      stream.puts "\t\t<system-err>&#xD;[File] #{filename}&#xD;[Line] #{item[:line]}&#xD;</system-err>"
      stream.puts "\t</testcase>"
    end
  end
  def write_tests( results, stream )
    result = results[:successes]
    result.each do |item|
      filename = File.join(results[:source][:path], File.basename(results[:source][:file], '.*'))
      stream.puts "\t<testcase classname=\"#{@unit_name}\" name=\"#{item[:test]}\" time=\"0\" />"
    end
  end
  def write_ignored( results, stream )
    result = results[:ignores]
    result.each do |item|
      filename = File.join(results[:source][:path], File.basename(results[:source][:file], '.*'))
      stream.puts "\t<testcase classname=\"#{@unit_name}\" name=\"#{item[:test]}\" time=\"0\">"
      stream.puts "\t\t<skipped message=\"#{item[:message]}\" type=\"Assertion\"/>"
      stream.puts "\t\t<system-err>&#xD;[File] #{filename}&#xD;[Line] #{item[:line]}&#xD;</system-err>"
      stream.puts "\t</testcase>"
    end
  end
  def write_footer( stream )
    stream.puts "</testsuite>"
  end
  
end
if __FILE__ == $0
  uts = UnityToJUnit.new
  begin
    #look in the specified or current directory for result files
    ARGV[0] ||= './'
    targets = "#{ARGV[0].gsub(/\\/, '/')}*.test*"
    results = Dir[targets]
    raise "No *.test* file found in '#{targets}'" if results.empty?
    uts.set_targets(results)
    
    #set the root path
    ARGV[1] ||= File.expand_path(File.dirname(__FILE__)) + '/'
    uts.set_root_path(ARGV[1])
    
    #run the summarizer
    puts uts.run
  rescue Exception => e
    uts.usage e.message
  end
end