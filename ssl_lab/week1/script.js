function toRed() {
    document.getElementById("main_para").style.color = "red";
}

function toBlue() {
    document.getElementById("main_para").style.color = "blue";
}

function make_prompt() {
    console.log("prompt was initiated");
    var name = document.getElementsByName("user_name")[0];
    alert("hello " + name.value + ". You are doing well!!");
}