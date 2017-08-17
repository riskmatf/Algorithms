## AVL STABLA

**AVL stablo** je **samobalansirajucje** binarno stablo pretrage.
Pored toga shto je ono samo balansirano, takodje je i svako njegovo podstablo balansirano.

**Slozenost** svih operacija(pretraga, umetanje elementa, brisanje elementa) je O(log(n)).

**Balansiranje** stabla se postize rotacijama pri umetanju elemanata.

                y                               x
               / \     Desna rotacija u y      /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Leva rotacija u x         T2  T3
Gde su T1, T2, T3 podstabla

**Kritichan chvor** je prvi chvor, pocevshi od dole, kod koga je razlika izmedju
visine levog i desnog podstabla veca od 2.

Razdvajamo 4 kritichne situacije:

  * **levo-levo**

z je kritichan chvor, a problem je nastao u **levom** podstablu **levog** potomka chvora z

             z                                      y
            / \                                   /   \
           y   T4      Desna rotacija u z        x      z
          / \          - - - - - - - - ->      /  \    /  \
         x   T3                               T1  T2  T3  T4
        / \
      T1   T2


  * **levo-desno**

z je kritichan chvor, problem je nastao u **desnom** podstablu **levog** potomka chvora z

         z                               z                           x
        / \                            /   \                        /  \ 
       y   T4  Leva rotacija u y      x    T4  Desna rotacija u z y      z
      / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
    T1   x                          y    T3                    T1  T2 T3  T4
        / \                        / \
      T2   T3                    T1   T2


  * **desno-desno**

z je kritichan chvor, a problem je nastao u **desnom** podstablu **desnog** potomka chvora z


      z                                y
     /  \                            /   \ 
    T1   y     Leva rotacija u z    z      x
        /  \   - - - - - - - ->    / \    / \
       T2   x                     T1  T2 T3  T4
           / \
         T3  T4


  * **desno-levo**

z je kritichan chvor, a problem je nastao u **levom** podstablu **desnog** potomka chvora z

       z                            z                            x
      / \                          / \                          /  \ 
    T1   y   Desna rotacija u y  T1   x    Leva rotacija u z  z      y
        / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
       x   T4                      T2   y                  T1  T2  T3  T4
      / \                              /  \
    T2   T3                           T3   T4
###Dodavanje elementa
Dodavanje se zapochinje dodavanjem elementa u BSP.

Zatim se, pochevshi od umetnutog chvora, na gore proveravaju 4 sluchaja.

###Brisanje elemnta
Brisanje se zapochinje obicnim brisanjem elemnta iz BSP.

Zatim se, pochevshi od umetnutog chvora, na gore proveravaju 4 sluchaja. 
