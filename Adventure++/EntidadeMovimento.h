#pragma once

#include "Entidade.h"
#include "AnimacaoMovimento.h"

namespace Entidade {

	class EntidadeMovimento: public Entidade
	{
	protected:
		float tempo;
		static ElementoGrafico::AnimacaoMovimento* pAnimacaoMovimento;
	public:
		EntidadeMovimento(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
		~EntidadeMovimento();
		void renderizar();

		//teste...
		void atualizar(const float tempo) = 0;
	};
}
