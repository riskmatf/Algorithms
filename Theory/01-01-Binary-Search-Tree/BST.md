## Binarna stabla pretrage

**Binarno stablo pretrage** je svako binarno stablo za koje važi da je vrednost svakog čvora veća od vrednosti svakog čvora u njegovom levom podstablu i manja od vrednosti svakog čvora u njegovom desnom podstablu.

Svaki čvor ima najviše dva deteta. Svako dete mora da bude ili list (nema nijedno dete) ili koren još jednog binarnog stabla pretrage.

**Visina** stabla je najduži put od korena do lista.

### Operacije sa stablom
Osnovne operacije su:

1. Ubacivanje elementa u stablo
2. Brisanje elementa iz stabla
3. Pretraga stabla

Sve operacije su prosečne složenosti O(log(n)), gde je n broj elemenata u stablu.

Medjutim, složenost najgoreg slučaja svih operacija je O(n). Do ovog slučaja dolazi kada je stablo **degenerisano**.

**Degenerisano** stablo je stablo gde za svaki roditeljski čvor, postoji samo jedno dete čvor.

        1
         \
          2
           \
            9
           /
          6
           \ 
            7
    primer degenerisanog stabla

Stablo je **balansirano** ukoliko je razlika visina njegovog levog i desnog podstabla manja do jednaka 1. Visina balansiranog stabla je proporcionalna log<sub>2</sub>(n)

Da do degenerisanog slučaja ne bi dolazilo, pribegava se korišćenju **samobalansirajućih** stabala. To su stabla koja pri operacijama ubacivanja i brisanja elementa vrše provere balanisarnosti stabla i, ukoliko neka od operacija poremeti to stanje, popravljaju to. Najpopularniji primeri samobalansirajućih stabala su **AVL** stabla i **Crveno-crna** stabla.

**Kompletno binarno stablo** je binarno stablo koje je skroz puno, sa mogućnošću izuzetka donjeg nivoa, koje je napunjeno sa leva na desno. U kompletnom binarnom stablu, svi čvorovi su najlevlje moguće. To je stablo sa n nivoa, gde za svaki nivo d <= n - 1, broj postojećih čvorova na nivou d je jednak 2<sup>d</sup>. Ovo znači da svi mogući čvorovi postoje na ovim nivoima.

               100              n=1
           /        \
          50        120         n=2
         /  \      /   \
        30  70    110   130     n=3
       /  \
      20  40                    n=4
      Primer kompletnog stabla


### Obilasci stabla

Postoje 3 načina da se stablo obiđe, tj da se posete svi njegovi čvorovi.
Svaki od 3 načina se sastoji iz 3 koraka.

In-order(levo-koren-desno):

1. Obilazak levog podstabla
2. Pristup korenu
3. Obilazak desnog podstabla

Pre-order(koren-levo-desno):

1. Pristup korenu
2. Obilazak levog podstabla
3. Obilazak desnog podstabla

Post-order(levo-desno-koren):

1. Obilazak levog podstabla
2. Obilazak desnog podstabla
3. Pristup korenu

Najčešće se koristi in-order obilzak, zato što on daje sortiran niz elemenata stabla.
