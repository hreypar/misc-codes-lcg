#Helena R Gopar. Metodos Numericos. Trapecios.
print"\nIntroduce tu funcion\n";
chomp($funcion=<STDIN>);
$funcion=~s/exp/esp/g;
$funcion=~s/x/\$x/g;
$funcion=~s/esp/exp/g;
print"\nIntroduce a (limite menor)\n";
chomp($a=<STDIN>);
print"\nIntroduce b (limite superior)\n";
chomp($b=<STDIN>);
print"\nIntroduce el numero de intervalos que quieres\n";
chomp($intervalos=<STDIN>);

$h=($b-$a)/$intervalos; #obtención del incremento h
$sum=0;
for($x=$a, $contador=0; $x<=$b; $x+=$h, $contador++) {
	
	$y=eval($funcion);
	$y/=2 if($contador ==0 || $contador == $intervalos); #el contador es para saber cuando hay que dividir entre dos (la y0 y la yn)
	$sum+=$y;
	#print"\n\nf($x)=$y\n"
	}
$area=$h*$sum;
print"\n\nY el area es $area\n\n";

