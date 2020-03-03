<section>
	<?php
		$editando = false;
		if(!empty($_GET)){
			$cliente = buscar_cliente($_GET["cliente"]);
			if(!empty($cliente)){
				$editando = true;
			}
		}
	?>
	<form action="form_cadastro_cliente.php" method="post">
		<fieldset>
			<legend>Cadastro de Cliente</legend>
			<p>
				<label>Código:</label>
				<input type="number" name="codigo"
					readonly="readonly"
					<?php
						if($editando){
							echo 'value="'.$cliente->codigo.'"';
						}else{
							$codigo = buscar_codigo("cliente");
							echo 'value="'.$codigo.'"';
						}	
					?>
				/>
			</p>

			<p>
				<label>Nome:</label>
				<input type="text" name="nome" size="30"
					<?php
						if($editando){
							echo 'value="'.$cliente->nome.'"';
						}
					?>
				/>
			</p>
			<p>
				<label>E-mail:</label>
				<input type="email" name="email" size="30"
					<?php
						if($editando){
							echo 'value="'.$cliente->nome.'"';
						}
					?>
				/>
			</p>

			<p>
				<label>Telefone:</label>
				<input type="text" name="telefone" 
					<?php
						if($editando){
							echo 'value="'.$cliente->telefone.'"';
						}
					?>
				/>
			</p>
			<p>
				<label>Data:</label>
				<input type="date" name="data" 
					<?php
						if($editando){
							echo 'value="'.$cliente->data.'"';
						}
					?>
				/>
				<label>Hora:</label>
				<input type="time" name="hora" 
					<?php
						if($editando){
							echo 'value="'.$cliente->hora.'"';
						}
					?>
				/>

			</p>
			
			<input type="hidden" name="modo"
				<?php
					if($editando){
						echo 'value="1"';
					}else{
						echo 'value="0"';
					}
				?>
			/>
			<input type="submit" value="Agendar"/>
		</fieldset>
	</form>
</section>