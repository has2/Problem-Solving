const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function(line) {
  arr = line.split(" ");
  a = Number(arr[0])
  b = Number(arr[1])
  if(a>b) console.log('>')
  if(a<b) console.log('<')
  if(a==b) console.log('==')
  rl.close();
}).on("close", function() {
  process.exit();
});