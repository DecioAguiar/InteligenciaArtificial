masculino(abraham).
masculino(clancy).
masculino(herbert).
masculino(homer).
masculino(bart).

feminino(mona).
feminino(jacqueline).
feminino(marge).
feminino(patty).
feminino(selma).
feminino(lisa).
feminino(maggie).
feminino(ling).

paioumae(abraham,herbert).
paioumae(abraham,homer).

paioumae(mona,herbert).
paioumae(mona,homer).

paioumae(homer,bart).
paioumae(homer,lisa).
paioumae(homer,maggie).

paioumae(marge,bart).
paioumae(marge,lisa).
paioumae(marge,maggie).

paioumae(clancy,marge).
paioumae(clancy,patty).
paioumae(clancy,selma).

paioumae(jacqueline,marge).
paioumae(jacqueline,patty).
paioumae(jacqueline,selma).

paioumae(selma,ling).

conjugue(homer,marge).
conjugue(clancy,jacqueline).
conjugue(abraham,mona).


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


%findall(R, filha(R,marge), L), sort(L,S).