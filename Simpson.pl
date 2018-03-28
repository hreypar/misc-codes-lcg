#Helena R Gopar. Metodos Numericos. Simpson.
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

$h=($b-$a)/$intervalos;
$sum=0;
for($x=$a, $contador=0; $x<=$b; $x+=$h, $contador++) {
	
	$y=eval($funcion);
	$y*=2 if ($contador%2 ==0); #ocupo modulo para saber si es una y par o no, tengo que multiplicar por 2 o por 4
	$y*=4 if ($contador%2 !=0);
	$y/=2 if($contador ==0 || $contador == $intervalos);
	$sum+=$y;
	#print"\n\nf($x)=$y\n"
	}
$area=($h/3)*$sum;
print"\n\nY el area es $area\n\n";

