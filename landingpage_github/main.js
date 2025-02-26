function modifyModal(modal,condition){
    document.querySelector(modal).style.display=condition;
}
function openCloseModal(modal){
    let modalElement = document.querySelector(modal);
    let modalContainer = document.querySelector("#modal");

    

    if(modalElement.style.display === "block"){
        modifyModal(modal,"none");
        console.log("fechou");
    }
    else if(modalElement.style.display === "none" || modalElement.style.display == ""){
        modifyModal(modal,"block");
        console.log("abriu");
    }
}

document.querySelector("#menu_button_about").addEventListener("click",
    function(){
        openCloseModal("#modal_about");
        event.stopPropagation();
    }
);

document.querySelector("#menu_button_projects").addEventListener("click",
    function(){
        openCloseModal("#modal_projects");
        event.stopPropagation();
    }
);

document.querySelector("#menu_button_contact").addEventListener("click",
    function(){
        openCloseModal("#modal_contact");
        event.stopPropagation();
    }
);

document.querySelector("html").addEventListener("click",
    function(event){
        modal = document.querySelector("#modal");
        if(!modal.contains(event.target)){
            Array.from(modal.children).forEach(function(child,index){
                child.style.display = "none";
            });
        }
    }
);