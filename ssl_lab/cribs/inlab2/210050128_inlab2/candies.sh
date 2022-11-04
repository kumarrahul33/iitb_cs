var1=0
var2=1
temp=0
s=1
echo $var1
while [ $s -lt $1 ]
do
        echo $var2
        temp=$var1
        var1=$var2
        var2=$((temp + var2))
        s=$((s + 1))
done