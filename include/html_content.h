extern const char *HTML_CONTENT = R""""(
<!DOCTYPE html>
<html>

<head>
    <title>Button Click Example</title>
    <script>
        function makeHttpRequest() {
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
    <button onclick="makeHttpRequest()">Click me to make an HTML call</button>
</body>

</html>
)"""";