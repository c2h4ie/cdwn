# cdwn
A simple timer/stopwatch utility written in c++
ps. code is old so expect some dumb stuff.

### Options
```
  -h [ --help ]         Print help messages
  -c [ --command ] arg  Command to execute
  -t [ --time ] arg     Time for countdown
  -s [ --stopwatch ]    Start stopwatch
```

### Example usage

 - ```cdwn -t 2m30s -c "echo Hello, World!"``` counts down 2m30s and executes ```echo Hello, World!```

 - ```cdwn -s``` starts a stopwatch 
