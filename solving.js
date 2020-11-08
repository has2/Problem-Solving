//bronze4 2753
_r = require('readline');
_rl = _r.createInterface({
  input: process.stdin,
  output: process.stdout
});

_rl.on('line', function(ip) {
  i = Number(ip)
  console.log(!(i%4) &&((i%100) || !(i%400)) ? 1 : 0)
  _rl.close();
}).on("close", function() {
  process.exit();
});