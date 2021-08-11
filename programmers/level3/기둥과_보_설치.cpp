var map = Array(202){Array(202){BooleanArray(2)}}
var checkFunc = listOf(
    {x:Int,y:Int -> y==1 || map[x][y-1][0] || map[x-1][y][1] || map[x][y][1]},
    {x:Int,y:Int -> (map[x-1][y][1] && map[x+1][y][1]) || map[x][y-1][0] || map[x+1][y-1][0] }
)
fun check(x:Int,y:Int,n:Int):Boolean{
    for(i in 1..n+1)
        for(j in 1..n+1){
            if(map[i][j][0] && !checkFunc[0](i,j)) return false
            if(map[i][j][1] && !checkFunc[1](i,j)) return false
        }
   return true
}
class Solution {
    fun solution(n: Int, build_frame: Array<IntArray>): Array<IntArray> {
        for((tx,ty,a,b) in build_frame){
            var x = tx+1
            var y = ty+1
            if(b==0){
                map[x][y][a]=false
                if(!check(x,y,n)) map[x][y][a]=true
            }else{
                if(checkFunc[a](x,y)) {
                    map[x][y][a]=true
                }
            }
        }
        var lst = mutableListOf<IntArray>()
        for(i in 1..n+1){
            for(j in 1..n+1){
                if(map[i][j][0]) lst.add(intArrayOf(i-1,j-1,0))
                if(map[i][j][1]) lst.add(intArrayOf(i-1,j-1,1))
            }
        }
        return lst.toTypedArray()
    }
}