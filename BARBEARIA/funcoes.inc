<?php
	function buscar_codigo($entidade){
		if(file_exists("sequencia_codigos.xml")){
			$xml = simplexml_load_file("sequencia_codigos.xml");
			switch($entidade){
				case "cliente":
					return $xml->cliente;

			}
		}else{
			$xml =
				'<?xml version="1.0" encoding="UTF-8" ?>
				<codigos>
					<cliente>1</cliente>
				</codigos>';
			
			file_put_contents("sequencia_codigos.xml", $xml);
			return 1;
		}
	}

	function atualiza_codigo($entidade){
		if(file_exists("sequencia_codigos.xml")){
			$xml = simplexml_load_file("sequencia_codigos.xml");
			switch($entidade){
				case "cliente":
					$xml->cliente++;
					break;

			}
			file_put_contents("sequencia_codigos.xml", $xml->asXML());
		}
	}
	
	function ler_dados_cliente(){
		$codigo = $_POST["codigo"];
		$nome = $_POST["nome"];
		$email = $_POST["email"];
		$telefone = $_POST["telefone"];
		$data = $_POST["data"];
		$hora = $_POST["hora"];

		
		$modo = $_POST["modo"];
		if($modo == 0){
			if(!file_exists("clientes.xml")){
				$xml =
					'<?xml version="1.0" encoding="UTF-8" ?>
					<clientes>
						<cliente>
							<codigo>'.$codigo.'</codigo>
							<nome>'.$nome.'</nome>
							<email>'.$email.'</email>
							<telefone>'.$telefone.'</telefone>
							<data>'.$data.'</data>
							<hora>'.$hora.'</hora>
						</cliente>
					</clientes>';
					file_put_contents("clientes.xml", $xml);
					
			}else{
				$xml = simplexml_load_file("clientes.xml");
				$cliente = $xml->addChild("cliente");
				$usuario->addChild("codigo", $codigo);
				$cliente->addChild("nome", $nome);
				$cliente->addChild("email", $email);
				$cliente->addChild("telefone", $telefone);
				$cliente->addChild("data", $data);
				$cliente->addChild("hora", $hora);
				file_put_contents("clientes.xml", $xml->asXML());
			}
			atualiza_codigo("cliente");
			echo "<section>
					<h2>Agendamento realizado com sucesso.</h2>
				</section>";
		}else{
			$xml = simplexml_load_file("clientes.xml");
			foreach($xml->children() as $cliente){
				if($cliente->codigo == $codigo){
					$cliente->nome = $nome;
					$cliente->email = $email;
					$cliente->telefone = $telefone;
					$cliente->data = $data;
					$cliente->hora = $hora;	
				}
			}
			file_put_contents("clientes.xml", $xml->asXML());
			echo "<section>
					<h2>Cliente editado com sucesso.</h2>
				</section>";
		}
	}



	function lista_clientes(){
		$xml = simplexml_load_file("clientes.xml");
		foreach($xml->children() as $cliente){
			echo "<tr>
					<td>$cliente->nome</td>
					<td>$cliente->email</td>
					<td>$cliente->telefone</td>
					<td>$cliente->data</td>
					<td>$cliente->hora</td>";
			echo "<td><a href=\"form_cadastro_cliente.php?
							cliente=$cliente->codigo\">editar</a></td>
				<td><a href=\"excluir_cliente.php?
							cliente=$cliente->codigo\">excluir</a></td>
				</tr>";
		}
	}
	function buscar_cliente($codigo){
		if(file_exists("clientes.xml")){
			$xml = simplexml_load_file("clientes.xml");
			foreach($xml->children() as $cliente){
				if($cliente->codigo == $codigo){
					return $cliente;
				}
			}
		
		}
	}

?>