masculino(tywin).
masculino(robert).
masculino(jaime).
masculino(tyrion).
masculino(joffrey).
masculino(tommem).

feminino(joanna).
feminino(cersei).
feminino(sansa).
feminino(margaery).
feminino(myrcella).

paioumae(tywin,cersei).
paioumae(tywin,jaime).
paioumae(tywin,tyrion).

paioumae(joanna,cersei).
paioumae(joanna,jaime).
paioumae(joanna,tyrion).

paioumae(jaime,joffrey).
paioumae(jaime,tommen).
paioumae(jaime,myrcella).

paioumae(cersei,joffrey).
paioumae(cersei,tommen).
paioumae(cersei,myrcella).

conjugue(robert,cersei).
conjugue(tywin,joanna).
conjugue(tyrion,sansa).
conjugue(joffrey,margaery).
conjugue(tommen,margaery).


pai(X,Y) :- paioumae(X,Y),masculino(X).
mae(X,Y) :- paioumae(X,Y),feminino(X).

irmao(X,Y) :- paioumae(Z,X), paioumae(Z,Y), X\=Y, masculino(X).
irma(X,Y) :- paioumae(Z,X), paioumae(Z,Y), X\=Y, feminino(X).
irmaouirmao(X,Y) :- paioumae(Z,X), paioumae(Z,Y), X\=Y.

tio(X,Y) :- paioumae(Z,Y) , irmao(X,Z), masculino(X).
tia(X,Y) :- paioumae(Z,Y) , irma(X,Z), feminino(X).

avoouavo(X,Y) :- paioumae(Z,Y), paioumae(X,Z).
avoo(X,Y) :- paioumae(Z,Y), paioumae(X,Z), feminino(X).

primo(X,Y) :- (paioumae(Z,X), paioumae(W,Y), irmao(Z,W)) ; (paioumae(Z,X), paioumae(W,Y), irma(Z,W)).

descente(X,Y) :- paioumae(Y,X).
descendente(X,Y) :- paioumae(Z,X), descendente(Z,Y).

filhooufilha(X,Y) :- paioumae(Y,X).
filho(X,Y) :- paioumae(Y,X), masculino(X).
filha(X,Y) :- paioumae(Y,X), feminino(X).

esposa(X,Y) :- conjugue(Y,X) ; conjugue(X,Y), feminino(X).
marido(X,Y) :- conjugue(X,Y) ; conjugue(Y,X), masculino(X).

netoouneta(X,Y) :- paioumae(Z,X), filhooufilha(Z,Y).


%findall(R, irmaouirmao(R,joffrey), L), sort(L,S).
%findall(R, filhooufilha(R,robert), L), sort(L,S).
%findall(R, filha(R,tywin), L), sort(L,S).
%findall(R, irma(R,tyrion), L), sort(L,S).
%pai(jaime,joffrey), tio(jaime,joffrey).
%findall(R, avoouavo(R, tommen), L), sort(L,S).