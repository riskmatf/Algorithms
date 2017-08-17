## AVL STABLA

**AVL stablo** je **samobalansirajuće** binarno stablo pretrage.
Pored toga što je ono samo balansirano, takođe je i svako njegovo podstablo balansirano.

**Slozenost** svih operacija(pretraga, umetanje elementa, brisanje elementa) je O(log(n)).

**Balansiranje** stabla se postize rotacijama pri umetanju elemanata.

                y                               x
               / \     Desna rotacija u y      /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Leva rotacija u x         T2  T3
Gde su T1, T2, T3 podstabla

**Kritičan čvor** je prvi čvor, počevši od dole, kod koga je razlika između
visine levog i desnog podstabla veća od 2.

Razdvajamo 4 kritične situacije:

  * **levo-levo**

z je kritičan čvor, a problem je nastao u **levom** podstablu **levog** potomka čvora z

             z                                      y
            / \                                   /   \
           y   T4      Desna rotacija u z        x      z
          / \          - - - - - - - - ->      /  \    /  \
         x   T3                               T1  T2  T3  T4
        / \
      T1   T2


  * **levo-desno**

z je kritičan čvor, problem je nastao u **desnom** podstablu **levog** potomka čvora z

         z                               z                           x
        / \                            /   \                        /  \ 
       y   T4  Leva rotacija u y      x    T4  Desna rotacija u z y      z
      / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
    T1   x                          y    T3                    T1  T2 T3  T4
        / \                        / \
      T2   T3                    T1   T2


  * **desno-desno**

z je kritičan čvor, a problem je nastao u **desnom** podstablu **desnog** potomka čvora z


      z                                y
     /  \                            /   \ 
    T1   y     Leva rotacija u z    z      x
        /  \   - - - - - - - ->    / \    / \
       T2   x                     T1  T2 T3  T4
           / \
         T3  T4


  * **desno-levo**

z je kritičan čvor, a problem je nastao u **levom** podstablu **desnog** potomka čvora z

       z                            z                            x
      / \                          / \                          /  \ 
    T1   y   Desna rotacija u y  T1   x    Leva rotacija u z  z      y
        / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
       x   T4                      T2   y                  T1  T2  T3  T4
      / \                              /  \
    T2   T3                           T3   T4
### Dodavanje elementa
Dodavanje se započinje dodavanjem elementa u BSP.

Zatim se, počevši od umetnutog čvora, na gore proveravaju 4 slučaja.

### Brisanje elemnta
Brisanje se započinje obicnim brisanjem elemnta iz BSP.

Zatim se, počevši od umetnutog čvora, na gore proveravaju 4 slučaja. 
