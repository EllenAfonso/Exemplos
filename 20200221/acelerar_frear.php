<?php
	include "classCarro.php";
	include "cabecalho.php";
	
	$id = $_POST["id"];
	$tipo = $_POST["tipo"];
	$aceleração_frenagem = $_POST["aceleração_frenagem"];
	$tempo = $_POST["tempo"];
	
	if($tipo == "a"){
		$_SESSION["carro"][$id]-> acelerar($tempo, $aceleracao_frenagem);
	}
	else{
		$_SESSION["carro"][$id]-> frear($tempo, $aceleracao_frenagem);
	}
	
	header("location: listarCarros.php");
?>