const char * MAIN_PAGE PROGMEM = R"=====(
<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
        integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>rute.</title>
</head>

<body>
    <nav class="navbar navbar-expand-md navbar-dark bg-dark mb-4">
        <a class="navbar-brand" href="#">rute.</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarCollapse"
            aria-controls="navbarCollapse" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarCollapse">
            <!-- <ul class="navbar-nav mr-auto">
                <li class="nav-item active">
                    <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#">Link</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
                </li>
            </ul>
            <form class="form-inline mt-2 mt-md-0">
                <input class="form-control mr-sm-2" type="text" placeholder="Search" aria-label="Search">
                <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
            </form> -->
        </div>
    </nav>
    <main role="main" class="container">
        <div class="jumbotron">
            <h1>Hello, world! I am rute.</h1>
            <a href="on">
                <button type="button" class="btn btn-lg btn-success">ON</button>
            </a>
            <a href="off">
                <button type="button" class="btn btn-lg btn-danger">OFF</button>
            </a>
            <div class="btn-group" role="group" aria-label="Rotações">
                <a href="rotate?angle=0">
                    <button type="button" class="btn btn-lg btn-primary">0</button>
                </a>
                <a href="rotate?angle=90">
                    <button type="button" class="btn btn-lg btn-primary">90</button>
                </a>
                <a href="rotate?angle=180">
                    <button type="button" class="btn btn-lg btn-primary">180</button>
                </a>
            </div>
            <div class="btn-group" role="group" aria-label="Movimentos">
                <a href="turn?direction=left">
                    <button type="button" class="btn btn-lg btn-primary">left</button>
                </a>
                <a href="turn?direction=right">
                    <button type="button" class="btn btn-lg btn-primary">right</button>
                </a>
                <a href="walk?direction=foward">
                    <button type="button" class="btn btn-lg btn-primary">foward</button>
                </a>
                <a href="walk?direction=back">
                    <button type="button" class="btn btn-lg btn-primary">back</button>
                </a>
            </div>
        </div>
    </main>
    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"
        integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo"
        crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"
        integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1"
        crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"
        integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM"
        crossorigin="anonymous"></script>
</body>

</html>
)=====";