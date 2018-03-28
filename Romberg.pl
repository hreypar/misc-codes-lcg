#Helena R Gopar. Metodos Numericos. Romberg
#Función interpreta
sub interpreta {
my $fun_nueva = $_[0];
my $x = $_[1];
my $out = 0;
$out =  eval($fun_nueva);
return ($out);
}

print"\nIntroduce tu funcion\n";
chomp($funcion=<STDIN>);
$funcion=~s/exp/esp/g;
$funcion=~s/x/\$x/g;
$funcion=~s/esp/exp/g;
print"\nCuantos decimales de precision quieres?\n";
chomp($precision=<STDIN>);
print"\nIntroduce a (limite menor)\n";
chomp($a=<STDIN>);
print"\nIntroduce b (limite superior)\n";
chomp($b=<STDIN>);
$error = 1;
#valores iniciales
$c=$b-$a;
$J[1]=((interpreta($funcion, $a))+(interpreta($funcion, $b)))/2;
$I[1][0]=$c*$J[1];
#print "\n\n(1)(0)$I[1][0] - ";

for($i=1; $error>(10**(-$precision)) ; $i++) {
$n=2**$i;
$sum=0;
#for para la sumatoria
for($g=1; $g<= $n/2; $g++) {
 $frac=((2*$g)-1)/$n;
 $h=$a+($frac*$c);
 $sum+=interpreta($funcion, $h);
}
$J[$n]=$J[$n/2]+$sum;
#Recorriendo dependiendo del numero de asteriscos
for($asterisco=0; $asterisco<=$i; $asterisco++) {
	if($asterisco==0){
	$I[$n][$asterisco]=(1/$n)*$c*$J[$n];
	#print "\n($n)($asterisco)$I[$n][$asterisco] - ";
	}
	else{
	$temporalita =(2**$asterisco)**2;
	$I[$n][$asterisco]=(1/($temporalita-1))*(($temporalita*$I[$n][$asterisco-1])-($I[$n/2][$asterisco-1]));
	#print "($n)($asterisco)$I[$n][$asterisco] - ";
	}
}
$error=abs(($I[$n][$i]-$I[$n][$i-1])/($I[$n][$i]));
$y = $I[$n][$i];
}

print "\n\nEl valor de Y es $y\n\n";

