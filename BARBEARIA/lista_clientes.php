<html lang="pt-BR">
	<head>
		<head>
		<meta charset="utf-8">
		<title>BARBEARIA - Listagem de clientes</title>
		<link rel="stylesheet" href="estilos.css">
	</head>
	</head>
	<body>
		<div class="container">
			
			<?php
				include "funcoes.inc";
				include "cabecalho.inc";
				include "menu.inc";
				if(file_exists("clientes.xml")){
					include "tabela_clientes.inc";
				}else{
					echo "<section>
							<h2>Nenhum cliente cadastrado.</h2>
						</section>";
				}
				include "rodape.inc";
			?>	
		</div>
	</body>
</html>		
		
		
		