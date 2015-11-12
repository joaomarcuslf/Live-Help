def git_console()
  while true
    puts "[add] [commit] [status] [pull] [push] [out]"
    print "git "
    action = gets.chomp
    if action == "add"
      puts "[.] [file_name]"
      print "git add "
      action = gets.chomp
      system("git add #{action}")
    elsif action == "commit"
      puts "[msg]"
      print "git commit -m "
      action = gets.chomp
      system("git commit -m \"#{action}\"")
    elsif action == "out"
      break
    else
      system("git #{action}")
    end
  end
end

def gcc_console(file_name)

  if  file_name.include? ".rb"
    system("ruby #{file_name}")
  elsif file_name.include? ".c"
    aval = system("gcc #{file_name}")
    system("./a.out") if aval == true
  elsif file_name.include? ".py"
    system("python #{file_name}")
  else
    puts "Error, not found"
  end


  print "Press ENTER"
  getOut = gets.chomp
end

print ">>>"
file_name = gets.chomp
while true
  print "\e[H\e[2J"
  print "joaomarcuslf#Rconsole >>>"
  console_input = gets.chomp

  if console_input == "git"
    git_console()
  elsif console_input == "run"
    gcc_console(file_name)
  elsif console_input == "exit"
    break
  else
    print "Not found"
  end
  puts ""
end
