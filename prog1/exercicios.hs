potencia base exp = if exp > 0
                    then (potencia base (exp-1))*base
                    else 1
raiz x = aux x 1
      where
      aux x base = if base*base <= x
                   then aux x (base+1)
                   else (base-1)
lista = [1,3,5,4,2]
maior a b = if a > b
            then a
            else b
mdc a = aux a 1
      where
      aux x base = if (x mod base) > 0
                   then  (aux x (base+1))
                   else if ((x mod base) == 0)
                   then (base+(aux x (base+1)))
                   else if (base >= (x/2))
                   then 0
                   else (-(base-1))
