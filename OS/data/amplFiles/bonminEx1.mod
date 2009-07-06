   # An Ampl version of toy


   var x binary;
   var z integer >= 0 <= 5;
   var y{1..2} >=0;
   minimize cost:
       - x - y[1] - y[2] ;

   subject to
       c1: ( y[1] - 1/2 )^2 + (y[2] - 1/2)^2 <= 1/4 ;
       c2: x - y[1] <= 0 ;
       c3: x + y[2] + z <= 2;


