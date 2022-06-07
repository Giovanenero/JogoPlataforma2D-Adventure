#include "Fundo.h"

Fundo::Fundo(Ids::Ids id, Entidade::Entidade* pJogador1) :
    Ente(id), 
    pJogador(pJogador1),
    pAnimacaoEstatica(new ElementoGrafico::AnimacaoEstatica())
{
    if (pJogador == nullptr) {
        std::cout << "ERRO: pJogador vazio - classe Fundo!" << std::endl;
        exit(1);
    }
    inicializacao();
}
Fundo::~Fundo() { }

void Fundo::inicializacao() {
    Matematica::CoordenadaF posicao(pJogador->getPosicao().x, pJogador->getPosicao().y);
    Matematica::CoordenadaF tamanho(Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getWindow()->getPosition().x, Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->getWindow()->getPosition().y);
    pAnimacaoEstatica->novaAnimacao("textura/Fundo/fundoFloresta.png", Ids::Ids::fundo_floresta, posicao, tamanho, Matematica::CoordenadaF(1.9f, 1.9f));
    pAnimacaoEstatica->novaAnimacao("textura/Fundo/fundoCaverna.jpg", Ids::Ids::fundo_caverna, posicao, tamanho, Matematica::CoordenadaF(2.0f, 1.9f));
}
void Fundo::atualizar() {
    pAnimacaoEstatica->setPosicao(Matematica::CoordenadaF(pJogador->getPosicao().x, pJogador->getPosicao().y));
    pAnimacaoEstatica->atualizar(Ids::Ids::fundo_floresta);
    pAnimacaoEstatica->renderizar();
}

void Fundo::executar() { }