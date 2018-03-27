#Helena R Gopar. Metodos numericos. Euler
print"\nIntroduce tu funcion\n";
chomp($funcion=<STDIN>);
$funcion=~s/exp/esp/g;
$funcion=~s/x/\$x/g;
$funcion=~s/y/\$y/g;
$funcion=~s/esp/exp/g;
print"\nIntroduce tu Xo\n";
chomp($x0=<STDIN>);
print"\nIntroduce Y($x0)\n";
chomp($y=<STDIN>);
print"\nDe cual x quiere encontrar el valor f(x)?\n";
chomp($n=<STDIN>);
print"\nCual es el incremento (h)?\n";
chomp($h=<STDIN>);

for($x=$x0; $x <= $n-$h; $x+=$h){

$y=$y+($h*(eval($funcion)));
$val = $x + $h;
print"\nEl valor de Y($val)es $y";

}