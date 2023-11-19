extern const char *HTML_CONTENT = R""""(
<!DOCTYPE html>
<html>

<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            margin: 0px;
            font-family: 'Trebuchet MS', sans-serif;
        }

        h1 {
            margin-top: 0.025rem;
            margin-bottom: 0.5rem;
        }

        .td-pr-0 {
            padding-right: 0rem;
        }

        button {
            width: 4rem;
        }

        .space {
            margin-bottom: 0.5rem;
            margin-right: 0.5rem;
        }

        .custom-range {
            margin-top: 0.5rem;
            margin-left: 1rem;
            width: 15rem;
        }

        .container {
            margin: 0.5rem;
        }

        .sticky-top {
            position: -webkit-sticky;
            position: sticky;
            top: 0;
            z-index: 1020
        }

        .navbar {
            width: 100%;
            height: 2.5rem;
            background-color: #353535;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .navbar-text {
            color: white;
            font-size: 1.5rem;
            text-align: center;
            font-weight: bold;
        }

        .grid-container {
            display: grid;
            grid-template-columns: 50% 50%;
        }

        .hazer-section {
            grid-row: 1 / 2;
            grid-column: 1 / 2;
        }

        .light-section {
            grid-row: 1 / 2;
            grid-column: 2 / 3;
        }

        input[type="range"] {
            /* Set height to create space for the thumb */
            height: 1rem;
            /* Customize appearance */
            -webkit-appearance: none;
            /* Set track color */
            background-color: #ddd;
            /* Change thumb border */
        }

        /* Thumb styles for WebKit browsers */
        input[type="range"]::-webkit-slider-thumb {
            /* Set width and height to modify the thumb size */
            width: 20px;
            /* Change width */
            height: 20px;
            /* Change height */
            /* Set background color or other styles */
            background-color: #007bff;
            /* Change thumb color */
            border: 1px solid #000000;
            /* Change thumb border */
            border-radius: 50%;
            /* Make thumb circular */
            -webkit-appearance: none;
            /* Remove default styling */
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

        .btn-success {
            --bs-btn-color: #fff;
            --bs-btn-bg: #198754;
            --bs-btn-border-color: #198754;
            --bs-btn-hover-color: #fff;
            --bs-btn-hover-bg: #157347;
            --bs-btn-hover-border-color: #146c43;
            --bs-btn-focus-shadow-rgb: 60, 153, 110;
            --bs-btn-active-color: #fff;
            --bs-btn-active-bg: #146c43;
            --bs-btn-active-border-color: #13653f;
            --bs-btn-active-shadow: inset 0 3px 5px rgba(0, 0, 0, 0.125);
            --bs-btn-disabled-color: #fff;
            --bs-btn-disabled-bg: #198754;
            --bs-btn-disabled-border-color: #198754
        }

        .btn-primary {
            --bs-btn-color: #fff;
            --bs-btn-bg: #0d6efd;
            --bs-btn-border-color: #0d6efd;
            --bs-btn-hover-color: #fff;
            --bs-btn-hover-bg: #0b5ed7;
            --bs-btn-hover-border-color: #0a58ca;
            --bs-btn-focus-shadow-rgb: 49, 132, 253;
            --bs-btn-active-color: #fff;
            --bs-btn-active-bg: #0a58ca;
            --bs-btn-active-border-color: #0a53be;
            --bs-btn-active-shadow: inset 0 3px 5px rgba(0, 0, 0, 0.125);
            --bs-btn-disabled-color: #fff;
            --bs-btn-disabled-bg: #0d6efd;
            --bs-btn-disabled-border-color: #0d6efd
        }
    </style>
    <title>Dmx Controller</title>
    <script>
        const baseUrl = "http://10.10.1.1";

        function makePutRequest(url, data) {
            console.log("HTTP-PUT-Call");
            console.log(data.fanLevel);
            var xhr = new XMLHttpRequest();
            xhr.open("PUT", baseUrl + url, true);
            xhr.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
            var jsonData = JSON.stringify(data);
            xhr.send(jsonData);
        }

        window.addEventListener("load", () => {
            const fanLevelRange = document.getElementById('fanLevelRange')
            fanLevelRange.addEventListener('change', onUpdateFanLevelRange)

            function onUpdateFanLevelRange() {
                var value = fanLevelRange.value;
                var data = {
                    fanLevel: value
                };
                makePutRequest("test.test", data);
            }
        })
        
        function onUpdateColorPicker() {
                const colorPicker = document.getElementById('colorPicker')
                var value = colorPicker.value;
                const hex = value.substring(1);
                updateRGBState(
                    parseInt(hex.substring(0, 2), 16),
                    parseInt(hex.substring(2, 4), 16),
                    parseInt(hex.substring(4, 6), 16)
                )
            }
        function updateRGBState(red, green, blue) {
            var data = {
                red: red,
                green: green,
                blue: blue
            };
            makePutRequest("/light/rgb", data);
        }
    </script>
</head>
<body>
    <div class="navbar sticky-top">
        <p class="navbar-text">DMX Controller</p>
    </div>
    <div class="container">
        <div class="grid-container">
            <div class="hazer-section">
                <h1>Hazer</h1>
                <button class="space btn btn-danger" onclick="makeHttpRequest()">STOP</button>
                <button class="space btn btn-success" onclick="makeHttpRequest()">START</button>
                <table>
                    <tr>
                        <td>
                            <label for="fanLevelRange"><b>Fan level</b></label>
                        </td>
                        <td>
                            <input type="range" class="custom-range" id="fanLevelRange" min="0" max="255">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <label for="volumeLevelRange"><b>Volume level</b></label>
                        </td>
                        <td>
                            <input type="range" class="custom-range" id="volumeLevelRange" min="0" max="255">
                        </td>
                    </tr>
                </table>
            </div>
            <div class="light-section">
                <h1>Light</h1>
                <table>
                    <tr>
                        <td>
                            <button class="space btn btn-danger" onclick="updateRGBState(0, 0, 0)">STOP</button><br />
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <button class="space btn btn-primary" onclick="onUpdateColorPicker()">LIGHT</button>
                        </td>
                        <td>
                            <label for="colorPicker"><b>RGB </b></label>
                            <input class="space" type="color" id="colorPicker">
                        </td>
                    </tr>
                </table>
            </div>
        </div>
    </div>
</body>

</html>
)"""";