# code-arduino

## Tydzień 1 code-arduino "Dioda LED i przycisk"

### Misja 1.2

Wykonaj układ migającej diody LED (0,5 sekundy świeci, 0,5 sekundy nie świeci czyli okres migania to 0,5s+0,5s=1s).

[Wideo](https://youtu.be/b-HtH7E3UxQ)


### Misja 1.3

Zaprogramuj miganie diody LED za pomocą niekończącej się pętli while(1).

[Wideo](https://youtu.be/6VuT4UYh6A4)


### Misja 1.4

Wyświetl za pomocą diody LED słowo zapisane w alfabecie Morsa np. „SOS”.

[Wideo](https://youtu.be/BaZnMTMjAFY)


### Misja 1.5

Podłącz przycisk i użyj go w taki sposób żeby naciśnięcie przycisku powodowało zapalenie się diody LED.

[Wideo](https://youtu.be/nH8uBsx95vo)


### Misja 1.6

Użyj przycisk w taki sposób żeby naciśnięcie przycisku powodowało miganie diody LED.

[Wideo](https://youtu.be/uVLTvePThfM)


### Misja 1.7

Zmodyfikuj program żeby dioda LED wyświetlała słowo alfabetem Morsa po naciśnięciu przycisku.

[Wideo](https://youtu.be/p-VDETMK13c)


### Misja 1.8*

W układzie migającej diody LED zaprogramuj ją tak żeby po 10 zapaleniach dioda LED zgasła i już się nie zapaliła. W tym celu użyj instrukcji if( )


### Misja 1.9*

W układzie migającej diody LED zaprogramuj ją tak żeby dioda po 10 zapaleniach gasła na 3 sekundy po czym znów migała 10 razy, i tak w kółko. Wykorzystaj tutaj pętle for( lub pętle while(1) wraz z instrukcją if(


### Misja 1.d***

Napisz zamek szyfrowy. Wykorzystaj schemat podłączeń z układu 1.7. Trzy-cyfrowe hasło jest podawane w kodzie jedynkowym lub Morsa za pomocą przycisku. Dioda LED określa stan zamku: dioda nie świeci – zamek zamknięty, dioda miga – zamek otwarty, dioda świeci – zamek odczytuje kod z przycisku. Jeśli kod zostanie podany poprawnie zamek się otwiera, w innych przypadkach zamek pozostaje zamknięty.

[Wideo](https://youtu.be/-ZObxOV5o7c)


## Tydzień 2 code-arduino "Linijka LED i efekty świetlne"

### Misja 2.1: Wykonaj linijkę LED

Podłącz diody LED do pinów cyfrowych od pinu 2 do pinu 13. Wykonaj efekt „Knight Rider” czyli przesuwający się punkt. W danym momencie świeci się tylko jedna dioda LED, po czym gaśnie i zapala się dioda koło niej. Wykorzystaj pętle for( lub while(.


### Misja 2.2: Wykonaj efekt „Knight Rider” bez użycia pętli.

Użyj zmiennej globalnej która wskazuje który punkt w danym momencie się świeci i drugiej zmiennej globalnej wskazującej kierunek poruszania się punktu.


### Misja 2.3: Wykonaj efekt przesuwającego się świecącego punktu.

Punkt świetlny ma przesuwać się z jednej strony na drugą. Każda kolejna dioda świeci się o połowę krócej od poprzedniej. Po dojściu punktu do końca linijki wyświetlanie zaczyna się od nowa z początkową prędkością. Pierwsza dioda ma świecić się 1 sekundę, druga 0,5 sekundy itd. Wykorzystaj pętle for( lub while(.


### Misja 2.4: Podłącz dwa przyciski do któryś z pinów od A0 do A5.

Naciśnięcie jednego przycisku powoduje że pierwsza dioda LED się zaświeci, kolejne naciśnięcie przycisku zaświeci kolejną diodę LED, kolejne naciskanie przycisku zaświeci kolejne diody LED, do momentu aż wszystkie będą się świecić. Drugi przycisk powoduje zgaszenie ostatniej diody LED, wielokrotne naciskanie tego przycisku wygasi kolejne diody LED, aż do momentu gdzie żadna dioda LED nie będzie się świecić. Nie ważne jak długo przycisk jest naciśnięty ma zapalać lub gasić tylko jedną diodę LED.


### Misja 2.5: Efekt „Knight Rider” ze zmienną szybkością.

Przyciski mają zmieniać szybkość przesuwania się punktu. Jeden przycisk przyśpiesza przesuwanie poprzez zmniejszenie o połowę czasu przez jaki świeci się jedna dioda, a drugi przycisk zwalnia przesuwanie poprzez zwiększenie dwukrotnie czasu przez jaki świeci się jedna dioda. Wielokrotne naciśnięcie przycisku powoduje wielokrotne przyśpieszenie lub zwolnienie efektu. Zakres świecenie się jednej diody LED to od 2 sekund do 2 milisekund.


### Misja 2.6: Zaprogramuj 4 różne efekty świetlne na linijce diod LED.

Jeden przycisk zmienia pomiędzy efektami. Każdy efekt może działać w 5 różnych prędkościach. Drugi przycisk zmienia pomiędzy prędkościami.


### Misja 2.7: Zmiana jasności.

Zaprogramuj miganie linijki diod LED jednocześnie w stałym okresie 5 milisekund (patrz misja 1.2 z poprzedniego tygodnia). Wszystkie diody mają się świecić razem przez 1 milisekundę w okresie 5 milisekundowym. Przyciskami zwiększ i zmniejsz czas świecenie diod o 1 milisekundę. Możliwe czasy świecenia diod to od 0 milisekund świecenia (diody LED są wtedy zupełnie wygaszone), aż do 5 milisekund (diody LED świecą się wtedy najmocniej).


### Misja 2.8: Płynna zmiana jasności.

Zaprogramuj miganie linijki diod LED jednocześnie w stałym okresie 5 milisekund. Wszystkie diody mają się świecić razem. Czas świecenia diod zmieniaj automatycznie od 0 milisekund do 5 milisekund i z powrotem do 0 milisekund. Zmieniaj czas świecenia diod o 1 milisekundę w danym momencie. Zmiany czasu świecenia wykonuj co 0,1 sekundy. Przyciskami zmieniaj ten czas w zakresie od 0,05 sekundy do 0,5 sekundy.


### Misja 2.9: Fala.

Zaprogramuj miganie diod w okresie 5 milisekund. Pierwsza dioda ma świecić się przez 5 milisekund (będzie cały czas zapalona), Druga dioda ma świecić się przez 4 milisekundy Trzecia dioda ma świecić się przez 3 milisekundy Czwarta dioda ma świecić się przez 2 milisekundy Piąta dioda ma świecić się przez 1 milisekundę Szósta i kolejne diody mają świecić się przez 0 milisekund (będą zgaszone) Przyciskami przesuwaj „falę” (pierwszą i kolejne diody) o jeden w prawo i o jeden w lewo.


### Misja 2.a: Efekt „Knight Rider" zaawansowany.

Zaprogramuj miganie diod w okresie 5 milisekund. Pierwsza dioda świeci się przez 5 milisekund, kolejna 4 milisekundy, kolejna 3 milisekundy itd. Co 0,3 sekundy świecąca fala przesuwa się o jedną diodę. Przyciskami można zwiększać i zmniejszać szybkość przesuwania się fali.


### Misja 2.b: Wyświetl 10 bitową liczbę binarną na linijce diod LED.

Każda dioda odpowiada jednej cyfrze liczby binarnej. Naciśnięcie przycisku zwiększa wyświetlaną liczbę o 1, naciśnięcie drugiego przycisku zmniejsza wyświetlaną liczbę o 1. Dłuższe przytrzymanie przycisków (powyżej 1 sekundy) powoduje szybkie zwiększanie lub zmniejszanie liczby (np. o 1 co 100 milisekund wciśniętego przycisku). Zakres wyświetlanej liczby to od 0 do 1023.


### Misja 2.c*: Wykonaj wszystkie zadania z listy dla diod LED podłączonych od pinu 0 do pinu 13.

Jeśli masz problemy z wgraniem programu na Arduino UNO odgadnij skąd ten problem się bierze i jak go rozwiązać.


### Misja 2.d*: Wyświetl 9 bitową liczbę ze znakiem w kodzie U2 na linijce diod LED.

Każda dioda odpowiada jednej cyfrze liczby binarnej. Naciśnięcie przycisku zwiększa wyświetlaną liczbę o 1, naciśnięcie drugiego przycisku zmniejsza wyświetlaną liczbę o 1. Dłuższe przytrzymanie przycisków (powyżej 1 sekundy) powoduje szybkie zwiększanie lub zmniejszanie liczby (np. o 1 co 100 milisekund wciśniętego przycisku). Zakres wyświetlanej liczby to od -256 do 255.


### Misja 2.e*: Płynna animacja.

Zaprogramuj miganie diod LED w okresie 1,5 milisekundy. Diody mogą świecić od 0 milisekund do 1,5 milisekundy co 0,1 milisekundy. W ten sposób wykonaj chodzącą linijkę LED żeby przesuwający się punkt składał się z dwóch diod LED które sumarycznie świecą się przez 1,5 milisekundy (np.: jedna świeci się przez 0,5 milisekundy, a druga przez 1,0 milisekundy). Dioda w kierunku której punkt się porusza ma świecić się coraz dłużej, a dioda z której strony punkt idzie ma świecić się coraz krócej. Kiedy „tylna” dioda zgaśnie, nowa dioda po stronie w którą punkt się przesuwa zacznie świecić coraz dłużej, a dioda która przed chwilą świeciła się przez 1,5 milisekundy zacznie świecić krócej itd.


### Misja 2.f**: Kula na równoważni.

Wykorzystaj wyświetlanie z poprzedniej misji. Wyświetlany punkt reprezentuję kulę która znajduję się na równoważni. Kula po resecie znajduje się na środku i ma prędkość zerową. Dwa przyciski służą do przechylania równoważni w jedną bądź drugą stronę. Naciśnięcie przycisku przechyla równoważnię w stronę przycisku. Wielokrotne naciśnięcie przycisku przechyla równoważnię o wielokrotność kąta. Przy przechyleniu kula rozpędza się lub hamuje zgodnie ze swoim pędem i momentem obrotowym. Kiedy kula „wyjedzie” z pola wyświetlacza automatycznie „wjeżdża” z drugiej strony wyświetlacza.


### Misja 2.g***: GRA „kula na równoważni”

Wykorzystaj równoważnię z poprzedniej misji. Kiedy kula wyjedzie z jednej ze stron następuje koniec gry. Co pięć sekund zwiększa się poziom trudności który powoduje że równoważnia staje się coraz bardziej wypukła (symulacja wypukłości za pomocą pochodnej funkcji cosinus czyli sinus). Zwiększenie poziomu trudności pokazane jest zamiganiem diodami lub dźwiękiem z buzera (potrzebna jest zamiana pinów linijki LED żeby podłączyć buzer do PWM). Kiedy kula spadnie wyświetlany jest w kodzie binarnym czas gry zapisany w dziesiątej części sekund.

