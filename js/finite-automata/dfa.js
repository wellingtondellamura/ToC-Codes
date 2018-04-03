var tape= document.getElementById("tape");
var result= document.getElementById("result");
var run= document.getElementById("run");
var clear= document.getElementById("clear");


run.addEventListener("click", function(){
   execute(tape.value);
});

clear.addEventListener("click", function(){
   tape.value = "";
   result.innerText = "";
   tape.focus();
});

var showResult = function(accept){
   if (accept){
      result.style.color = "green";
      result.innerText = "accepted";
   }  else {
      result.style.color = "red";
      result.innerText = "rejected";
   }
}

var start = 0;
var final = [3];

var execute = function(tape){
   var current = start;
   for (var i = 0; i < tape.length; i++) {
      var symbol = tape.charAt(i);
      current = delta(current, symbol);
      if (current == -1){
         break;
      }
   }
   showResult(final.includes(current));
}


var delta = function(state, symbol){
   switch(state){
      case 0:
         if (symbol == 'a') return 1;
         if (symbol == 'b') return 0;
         if (symbol == 'c') return 0;
         break;

      case 1:
         if (symbol == 'a') return 1;
         if (symbol == 'b') return 2;
         if (symbol == 'c') return 0;
         break;

      case 2:
         if (symbol == 'a') return 1;
         if (symbol == 'b') return 3;
         if (symbol == 'c') return 0;
         break;

      case 3:
         if (symbol == 'a') return 1;
         if (symbol == 'b') return 0;
         if (symbol == 'c') return 0;
         break;
   }
   return -1;
}
