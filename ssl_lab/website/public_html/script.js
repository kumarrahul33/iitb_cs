function make_prompt() {
    console.log("prompt was initiated");
    const hobbies = ["guitar","books","running","music","badminton"]
    var userData = [];
    hobbies.forEach(element => {
        console.log(document.getElementById(element).checked);
        if (document.getElementById(element).checked == true) {
            userData.push(element);
        }
    });
    console.log(userData);
    var output = ""; 
    userData.forEach(element => {
        output += element + "\n";
    });
    console.log(output);
    Swal.fire(
    {
        title: "You Selected :",
        showDenyButton: true,
        confirmButtonText : "Yes",
        denyButtonText:"No",
        text: output
    }).then((result) => {
        if (result.isConfirmed) {
            userData.forEach(element => {
            var temp = element + "_data";
            document.getElementById(temp).style.display = 'block';
            });
        }
        else{
            hobbies.forEach(element => {
                document.getElementById(element).checked = false;
                hobbies.forEach(element => {
                   var temp = element + "_data";
                   
                   document.getElementById(temp).style.display = 'none';
                });
            });
        }
    });
      
}
