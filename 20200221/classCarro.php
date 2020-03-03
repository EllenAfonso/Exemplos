<?php
	class Carro{
		//Lista de Atributos
		private $cor;
		private $qtd_porta;
		private $velocidade_maxima;
		private $velocidade_atual;
		
		public function __construct($c, $qp, $vm){
			$this->cor = $c;
			$this->qtd_porta = $qp;
			$this->velocidade_maxima = $vm;
			$this->velocidade_atual = 0;
		}
		
		public function get_cor(){
			return($this->cor);
		}
		
		public function get_qtd_porta(){
			return($this->qtd_porta);
		}
		
		public function get_velocidade_maxima(){
			return($this->velocidade_maxima);
		}
		
		public function get_velocidade_atual(){
			return($this->velocidade_atual);
		}
		
		
	
		
		
		
		//Lista de Métodos
		public function acelerar($valor_aceleracao, $tempo){
			//implementação
			$this->velocidade_atual = $this->velocidade_atual + $valor_aceleracao * $tempo;
		}
		
		public function frear($valor_frenagem, $tempo){
			//implementação
			$this->velocidade_atual = $this->velocidade_atual - $valor_frenagem * $tempo;
			
		}
		
		public function virar($lado){
			//implementação
			
		}
		
	}
?>