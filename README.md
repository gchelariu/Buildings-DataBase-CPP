# Baza-de-date-a-cladirilor-pe-o-anumita-asezare

Dându-se de la tastatură comenzi de adăugare/ștergere a unor clădiri sau a unor persoane cu statuturi diferite în acele clădiri, să se facă o statistică asupra anumitor atribute ce țin de anumite tipuri de persoane sau de tipul așezării, așa cum este spus în secțiunea de Date de ieșire. Ceea ce se vrea este crearea unei așezări, care poate fi sat, oraș sau capitală, depinzând de numărul și de tipul clădirilor care se dau de la tastatură să fie adăugate în acea așezare.

Date de intrare:

primul cuvânt va fi acțiunea pe care vreți să o faceți.
al doilea cuvânt este ceea ce vreți să adăugați sau să ștergeți.
dacă vrem să adăugăm o clădire, următoarea dată de intrare va fi numele clădirii.
dacă vrem să adăugăm o persoană, următoarele date de la intrare vor fi numele persoanei, vârsta persoanei, salariul persoanei și numele clădirii în care vrem să adăugăm acea persoană.
dacă vrem să ștergem o persoană, următoarele date de la intrare vor fi numele persoanei și numele clădirii.
Date de iesire:

Ieșirea va consta dintr-o statistică a așezării create folosind aceste clădirii astfel:

Type: tipul așezării. Acest tip poate fi "Village", "Town" sau "Capital". Pentru a știi ce tip de așezare avem, se vor va trebui: Capital: CityHall >=3, Hospital >= 2, PoliceStation >= 3, House >= 8, Block >= 4 City: CityHall >=2, Hospital >= 1, PoliceStation >= 2, House >= 4, Block >= 1 Village: Orice altceva în afară de condițiile de mai sus Number of patients in hospitals: numărul total de pacienți din toate spitalele Average salary for doctors: salariul mediu al tuturor doctorilor din toate spitalele Average salary for cops: salariul mediu al tuturor polițiștilor din toate secțiile de poliție Average salary for mayors: salariul mediu al tuturor primarilor din toate primăriile Average salary for city hall employees: salariul mediu al tuturor angajaților din toate primăriile Average age of busted in police stations: vârsta medie a tuturor persoanelor arestate din toate secțiile de poliție Următoarele linii trebuie să fie de forma: Number of people in House numele_casei: numărul de persoane din acea casă, inclusiv proprietarul dacă există Number of people in Block numele_blocului: numărul de persoane din acel bloc, inclusiv administratorul dacă există Liniile de mai sus vor fi puse în ordinea în care au fost date casele și blocurile de la tastatură. Administrators of house and block: numele persoanelor care sunt și administratoare de bloc și proprietare de casă. Dacă nu există nicio persoană se va pune cuvântul Nobody.
