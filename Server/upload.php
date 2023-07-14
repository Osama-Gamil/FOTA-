<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Bootloader</title>

<link rel="stylesheet" href='https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css'>
<script src='https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.bundle.min.js'></script>
<link rel="stylesheet" href='https://use.fontawesome.com/releases/v5.7.2/css/all.css'>
<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>

<style>
body {
    background-color: #EBEAEF
}

.container {
    flex-wrap: wrap
}

.card {
    border: none;
    border-radius: 10px;
    background-color: #dc3545;
    width: 350px;
    margin-top: -60px
}

p.mb-1 {
    font-size: 25px;
    color: #9FB7FD
}

.btn-primary {
    border: none;
    background: #fff;
    margin-bottom: 60px
}

.btn-primary small {
    color: #9FB7FD
}

.btn-primary span {
    font-size: 13px
}

.card.two {
    border-top-right-radius: 60px;
    border-top-left-radius: 0
}

.form-group {
    position: relative;
    margin-bottom: 2rem
}

.form-control {
    border: none;
    border-radius: 0;
    outline: 0;
    border-bottom: 1.5px solid #E6EBEE
}

.form-control:focus {
    box-shadow: none;
    border-radius: 0;
    border-bottom: 2px solid #8A97A8
}

.form-control-placeholder {
    position: absolute;
    top: 15px;
    left: 10px;
    transition: all 200ms;
    opacity: 0.5;
    font-size: 80%
}

.form-control:focus+.form-control-placeholder,
.form-control:valid+.form-control-placeholder {
    font-size: 80%;
    transform: translate3d(0, -90%, 0);
    opacity: 1;
    top: 10px;
    color: #8B92AC
}

.btn-block {
    border: none;
    border-radius: 8px;
    background-color: #dc3545;
    padding: 10px 0 12px
}

.btn-block:focus {
    box-shadow: none
}

.btn-block span {
    font-size: 15px;
    color: #fff
}
 
</style>

</head>

<body>
<?php
if($_POST["username"]== "menashehata" && $_POST["password"]== "fotaiti"){

}
else{
echo '<script>alert("Welcome to Geeks for Geeks")</script>'; 
  header ("Location: index.html");
}

?>


  <div class="container d-flex justify-content-center">
    <div class="d-flex flex-column justify-content-between">
        <div class="card mt-3 p-5">
            <div>
                <p class="mb-1">ITI New Capital</p>
                <h4 class="mb-5 text-white">FOTA Project</h4>
				</div> <button class="btn btn-primary btn-lg"><small></small><span>&nbsp;</span> </button>
        </div>
	<form method="post" action="script.php" enctype="multipart/form-data">		
        <div class="card two bg-white px-5 py-4 mb-3">
            <div class="form-group"><input type="file" class="form-control" id="file" name="file" required></div>
			<button type="submit" class="btn btn-primary btn-block btn-lg mt-1 mb-2" value="Upload" name ="upload" id="upload"><span>Upload!<i class="fas fa-long-arrow-alt-right ml-2"></i></span></button>
        </div>
	</form>	
    </div>
</div>


</body>
</html>