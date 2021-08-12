lateinit var answer:IntArray
lateinit var referral:Array<String>
var table = hashMapOf<String,Int>()
fun sol(name:String,v:Int){
    if(name=="-" || v==0) return
    var a = 0
    if(v%10!=0) a=1
    answer[table[name]!!]+=(0.9*v).toInt()+a
    sol(referral[table[name]!!],(0.1*v).toInt())
}
class Solution {
    fun solution(enroll: Array<String>, _referral: Array<String>, seller: Array<String>, amount: IntArray): IntArray {
        referral = _referral
        answer = IntArray(enroll.size)
        for(i in enroll.indices) table[enroll[i]]=i
        for(i in seller.indices) sol(seller[i],amount[i]*100)
        return answer
    }
}