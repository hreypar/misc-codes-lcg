#Helena R Gopar. Metodos numericos. Regla Falsa.
$error=1;
print"\nIntroduce tu funcion\n";
chomp($funcion=<STDIN>);
$funcion=~s/exp/esp/g;
$funcion=~s/x/\$x/g;
$funcion=~s/esp/exp/g;

$funciona=$funcion; #crear duplicados de la funcion para poder evaluarla en a, b, k
$funciona=~s/exp/esp/g;
$funciona=~s/x/a/g;
$funciona=~s/esp/exp/g;
$funcionb=$funcion;
$funcionb=~s/exp/esp/g;
$funcionb=~s/x/b/g;
$funcionb=~s/esp/exp/g;
$funcionk=$funcion;
$funcionk=~s/exp/esp/g;
$funcionk=~s/x/k/g;
$funcionk=~s/esp/exp/g;

print"\nIntroduce a (limite menor)\n";
chomp($a=<STDIN>);
print"\nIntroduce b (limite superior)\n";
chomp($b=<STDIN>);
print"\nCuantos decimales de precision quieres?\n";
chomp($precision=<STDIN>);


$x=(($a*(eval($funcionb)))-($b*(eval($funciona))))/(eval($funcionb)-eval($funciona)); #x inicial 

$k=$a if(((eval($funciona))*(eval($funcion)))<0); 
$k=$b if(((eval($funcionb))*(eval($funcion)))<0);

while($error>(10**(-$precision))){

$y=(($x*(eval($funcionk)))-($k*(eval($funcion))))/(eval($funcionk)-eval($funcion)); 

$error= abs(($y-$x)/$y);
print"\nEl valor es $y y el error es $error\n";
$k=$x if(($x*$y)<0); #cuando hay cambio de signo k se convierte en x
$x=$y;

}