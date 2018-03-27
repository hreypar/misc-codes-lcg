#Helena R Gopar. Metodos numericos. Aproximaciones Sucesivas.
$error=1;
print"\nIntroduce tu funcion x=f(x)\n";
chomp($funcion=<STDIN>); #se guarda la función en la variable función y con el chomp le quitas el ultimo salto de linea.
$funcion=~s/exp/esp/g; #cambias la x de la funcion exp por una s para que no cambie cuando sustituimos las x 
$funcion=~s/x/\$x/g; #cambias las x caracter de la función por la variable x
$funcion=~s/esp/exp/g;#regresas los esp a exp
print"\nIntroduce tu Xo\n";
chomp($x=<STDIN>);
print"\nCuantos decimales de precision quieres?\n";
chomp($precision=<STDIN>);
print"\nIntroduce la primera derivada\n";
chomp($derivada=<STDIN>);
$derivada=~s/exp/esp/g;
$derivada=~s/x/\$x/g;
$derivada=~s/esp/exp/g;
die "\nEste programa se murio porque no hay convergencia!\n" if ((abs(eval($derivada)))<1); #evaluar el criterio de convergencia

while($error>(10**(-$precision))){ #se va a iterar hasta que el error deje de ser mayor que el error deseado

$y=eval($funcion); #evaluar la función
$error= abs(($y-$x)/$y);
print"\nEl valor es $y y el error es $error\n";
$x=$y; #actualizar x

}