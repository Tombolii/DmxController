extern const char *HTML_CONTENT = R""""(
<!DOCTYPE html>
<html>

<head>
    <script></script>
    <style>
        .sticky-top {
            position: -webkit-sticky;
            position: sticky;
            top: 0;
            z-index: 1020
        }

        .bg-dark {
            --bs-bg-opacity: 1;
            background-color: rgba(var(--bs-dark-rgb), var(--bs-bg-opacity)) !important
        }

        .flex-md-nowrap {
            flex-wrap: nowrap !important
        }

        .ps-2 {
            padding-left: .5rem !important
        }

        .mb-3 {
            margin-bottom: 1rem !important
        }

        .col-md-2 {
            flex: 0 0 auto;
            width: 16.66666667%
        }

        .col-sm-3 {
            flex: 0 0 auto;
            width: 25%
        }

        .navbar-brand {
            padding-top: var(--bs-navbar-brand-padding-y);
            padding-bottom: var(--bs-navbar-brand-padding-y);
            margin-right: var(--bs-navbar-brand-margin-end);
            font-size: var(--bs-navbar-brand-font-size);
            color: var(--bs-navbar-brand-color);
            text-decoration: none;
            white-space: nowrap
        }

        .navbar {
            --bs-navbar-padding-x: 0;
            --bs-navbar-padding-y: 0.5rem;
            --bs-navbar-color: rgba(var(--bs-emphasis-color-rgb), 0.65);
            --bs-navbar-hover-color: rgba(var(--bs-emphasis-color-rgb), 0.8);
            --bs-navbar-disabled-color: rgba(var(--bs-emphasis-color-rgb), 0.3);
            --bs-navbar-active-color: rgba(var(--bs-emphasis-color-rgb), 1);
            --bs-navbar-brand-padding-y: 0.3125rem;
            --bs-navbar-brand-margin-end: 1rem;
            --bs-navbar-brand-font-size: 1.25rem;
            --bs-navbar-brand-color: rgba(var(--bs-emphasis-color-rgb), 1);
            --bs-navbar-brand-hover-color: rgba(var(--bs-emphasis-color-rgb), 1);
            --bs-navbar-nav-link-padding-x: 0.5rem;
            --bs-navbar-toggler-padding-y: 0.25rem;
            --bs-navbar-toggler-padding-x: 0.75rem;
            --bs-navbar-toggler-font-size: 1.25rem;
            --bs-navbar-toggler-icon-bg: url("data:image/svg+xml,%3csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 30 30'%3e%3cpath stroke='rgba%2833, 37, 41, 0.75%29' stroke-linecap='round' stroke-miterlimit='10' stroke-width='2' d='M4 7h22M4 15h22M4 23h22'/%3e%3c/svg%3e");
            --bs-navbar-toggler-border-color: rgba(var(--bs-emphasis-color-rgb), 0.15);
            --bs-navbar-toggler-border-radius: var(--bs-border-radius);
            --bs-navbar-toggler-focus-width: 0.25rem;
            --bs-navbar-toggler-transition: box-shadow 0.15s ease-in-out;
            position: relative;
            display: flex;
            flex-wrap: wrap;
            align-items: center;
            justify-content: space-between;
            padding: var(--bs-navbar-padding-y) var(--bs-navbar-padding-x)
        }

        .navbar-dark,
        .navbar[data-bs-theme=dark] {
            --bs-navbar-color: rgba(255, 255, 255, 0.55);
            --bs-navbar-hover-color: rgba(255, 255, 255, 0.75);
            --bs-navbar-disabled-color: rgba(255, 255, 255, 0.25);
            --bs-navbar-active-color: #fff;
            --bs-navbar-brand-color: #fff;
            --bs-navbar-brand-hover-color: #fff;
            --bs-navbar-toggler-border-color: rgba(255, 255, 255, 0.1);
            --bs-navbar-toggler-icon-bg: url("data:image/svg+xml,%3csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 30 30'%3e%3cpath stroke='rgba%28255, 255, 255, 0.55%29' stroke-linecap='round' stroke-miterlimit='10' stroke-width='2' d='M4 7h22M4 15h22M4 23h22'/%3e%3c/svg%3e")
        }

        .btn {
            --bs-btn-padding-x: 0.75rem;
            --bs-btn-padding-y: 0.375rem;
            --bs-btn-font-family: ;
            --bs-btn-font-size: 1rem;
            --bs-btn-font-weight: 400;
            --bs-btn-line-height: 1.5;
            --bs-btn-color: var(--bs-body-color);
            --bs-btn-bg: transparent;
            --bs-btn-border-width: var(--bs-border-width);
            --bs-btn-border-color: transparent;
            --bs-btn-border-radius: var(--bs-border-radius);
            --bs-btn-hover-border-color: transparent;
            --bs-btn-box-shadow: inset 0 1px 0 rgba(255, 255, 255, 0.15), 0 1px 1px rgba(0, 0, 0, 0.075);
            --bs-btn-disabled-opacity: 0.65;
            --bs-btn-focus-box-shadow: 0 0 0 0.25rem rgba(var(--bs-btn-focus-shadow-rgb), .5);
            display: inline-block;
            padding: var(--bs-btn-padding-y) var(--bs-btn-padding-x);
            font-family: var(--bs-btn-font-family);
            font-size: var(--bs-btn-font-size);
            font-weight: var(--bs-btn-font-weight);
            line-height: var(--bs-btn-line-height);
            color: var(--bs-btn-color);
            text-align: center;
            text-decoration: none;
            vertical-align: middle;
            cursor: pointer;
            -webkit-user-select: none;
            -moz-user-select: none;
            user-select: none;
            border: var(--bs-btn-border-width) solid var(--bs-btn-border-color);
            border-radius: var(--bs-btn-border-radius);
            background-color: var(--bs-btn-bg);
            transition: color .15s ease-in-out, background-color .15s ease-in-out, border-color .15s ease-in-out, box-shadow .15s ease-in-out
        }

        .btn-danger {
            --bs-btn-color: #fff;
            --bs-btn-bg: #dc3545;
            --bs-btn-border-color: #dc3545;
            --bs-btn-hover-color: #fff;
            --bs-btn-hover-bg: #bb2d3b;
            --bs-btn-hover-border-color: #b02a37;
            --bs-btn-focus-shadow-rgb: 225, 83, 97;
            --bs-btn-active-color: #fff;
            --bs-btn-active-bg: #b02a37;
            --bs-btn-active-border-color: #a52834;
            --bs-btn-active-shadow: inset 0 3px 5px rgba(0, 0, 0, 0.125);
            --bs-btn-disabled-color: #fff;
            --bs-btn-disabled-bg: #dc3545;
            --bs-btn-disabled-border-color: #dc3545
        }

        .custom-range {
            width: 80%;
        }
    </style>
    <title>Dmx Controller</title>
    <script>
        function makePutRequest(url, data) {
            console.log("HTTP-PUT-Call");
            console.log(data.fanLevel);
            var xhr = new XMLHttpRequest();
            xhr.open("PUT", url, true);
            xhr.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
            var jsonData = JSON.stringify(data);
            xhr.send(jsonData);
        }

        window.addEventListener("load", () => {
            const fanLevelRange = document.getElementById('fanLevelRange')
            fanLevelRange.addEventListener('change', updateFanLevelRange)

            function updateFanLevelRange() {
                var value = fanLevelRange.value;
                var data = {
                    fanLevel: value
                };
                makePutRequest("test.test", data);
            }
        })





        function makeHttpRequest() {
            console.log("HTTP-Call")
            var xhr = new XMLHttpRequest();
            xhr.open("PUT", "http://10.10.1.1/hazer/state", true);
            xhr.setRequestHeader("Content-Type", "application/json;charset=UTF-8");

            var data = {
                fanLevel: 22,
                volumeLevel: 88
            };
            var jsonData = JSON.stringify(data);

            xhr.onreadystatechange = function () {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    // Handle the response here
                    var response = xhr.responseText;
                    console.log(response);
                }
            };
            xhr.send(jsonData);
        }
    </script>
</head>

<body>
    <nav class="navbar navbar-dark sticky-top bg-dark flex-md-nowrap ps-2 mb-3">
        <a class="navbar-brand col-sm-3 col-md-2" href="#">Dmx Controller</a>
    </nav>
    <div class="container">
        <div class="row mb-3">
            <div class="col">
                <h1>Hazer</h1></br>
                <button class="btn btn-danger" onclick="makeHttpRequest()">STOP</button>
            </div>
            <div class="col">
                <h1>Light</h1></br>
                <button class="btn btn-danger" onclick="makeHttpRequest()">STOP</button>
            </div>
        </div>

        <div class="row">
            <div class="col">
                <div class="row">
                    <div class="col-4">
                        <label for="fanLevelRange"><b>Fan level</b></label>
                    </div>
                    <div class="col-8">
                        <input type="range" class="form-range vertical-range custom-range h-100" id="fanLevelRange"
                            min="0" max="255">
                    </div>
                </div>
                <div class="row">
                    <div class="col-4">
                        <label for="volumeLevelRange"><b>Volume level</b></label>
                    </div>
                    <div class="col-8">
                        <input type="range" class="form-range vertical-range" id="volumeLevelRange" min="0" max="255">
                    </div>
                </div>
            </div>
            <div class="col">
            </div>
        </div>
    </div>



</body>

</html>
)"""";