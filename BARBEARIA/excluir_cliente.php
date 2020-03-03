<?php
    $codigo = $_GET["cliente"];
    if(file_exists("clientes.xml")){
        $xml = simplexml_load_file("clientes.xml");
        foreach($xml->children() as $cliente){
            if($cliente->codigo == $codigo){
                unset($cliente[0]);
                file_put_contents("clientes.xml", 
                        $xml->asXML());
                header("Location: lista_clientes.php");
            }
        }
    }
?>