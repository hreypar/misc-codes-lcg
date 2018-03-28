#Helena R Gopar. Metodos numericos. Runge-Kutta.
#Función interpreta
sub interpreta {
my $fun_nueva = $_[0];
my $x = $_[1];
my $y = $_[2];
my $out = 0;
$out =  eval($fun_nueva);
return ($out);
}

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
print"\nQue valor de X quiere encontrar?\n";
chomp($w=<STDIN>);
print"\nCual es el incremento (h)?\n";
chomp($h=<STDIN>);

$variableodiosa=abs(($w-$x0)/$h); #variable odiosa son los subintervalos

for($x=$x0,$contador=0; $contador<$variableodiosa; $contador++){


$k1=$h*eval($funcion);

$n=$x+($h/2);
$m=$y+($k1/2);
$k2=$h*interpreta($funcion, $n, $m);

$m=$y+($k2/2);
$k3=$h*interpreta($funcion, $n, $m);

$n=$x+$h;
$m=$y+$k3;
$k4=$h*interpreta($funcion, $n, $m);

$y=$y+(($k1+(2*$k2)+(2*$k3)+$k4)/6);

$val = $x + $h;
print"\nEl valor de Y($val)es $y\n";
$x+=$h

}