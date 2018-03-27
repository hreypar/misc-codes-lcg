#Helena R Gopar. Metodos numericos. Newton-Raphson.
$error=1;
print"\nIntroduce tu funcion\n";
chomp($funcion=<STDIN>);
$funcion=~s/exp/esp/g;
$funcion=~s/x/\$x/g;
$funcion=~s/esp/exp/g;
print"\nIntroduce tu Xo\n";
chomp($x=<STDIN>);
print"\nCuantos decimales de precision quieres?\n";
chomp($precision=<STDIN>);
print"\nIntroduce la primera derivada\n";
chomp($derivada=<STDIN>);
$derivada=~s/exp/esp/g;
$derivada=~s/x/\$x/g;
$derivada=~s/esp/exp/g;

while($error>(10**(-$precision))){
die "\nEste programa se murio porque no hay convergencia!.\n" if (!(eval($derivada))); 

$y=$x-(eval($funcion)/eval($derivada)); #es básicamente el mismo cuerpo que Aprox sucesivas, sólo cambia que ocupas la derivada para la formula 
$error= abs(($y-$x)/$y);
print"\nEl valor es $y y el error es $error\n";
$x=$y;

}