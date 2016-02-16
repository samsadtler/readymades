
var preveriousGamma = 0;
$(document).ready(function(){
	init();

	
});


function init(){
	console.log('init')
	preload();

	window.addEventListener('deviceorientation', handleOrientation);
	// window.addEventListener("resize" , checkWidth);
}



function preload() {
  mySound = loadSound('assets/doorbell.mp3');
}
function setup() {
  mySound.setVolume(0.1);
  mySound.play();
}

function handleOrientation(event) {
  	var absolute = event.absolute;
  	var alpha    = event.alpha;
  	var beta     = event.beta;
	var gamma    = event.gamma;
	var buffer   = 10;
	console.log('absolute: ', absolute, ' alpha: ', alpha, ' beta: ', beta, 'gamma: ', gamma)
 	
 	if (gamma > preveriousGamma + buffer){	
 		preveriousGamma = gamma;
		
	}
	if (gamma < preveriousGamma - buffer){
		preveriousGamma = gamma ;

	}

  // Do stuff with the new orientation data
}
