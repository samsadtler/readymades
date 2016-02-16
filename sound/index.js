
var preveriousGamma = 0;
var soundsArray = [
	'assets/vibemotor.m4a',
	'assets/vibemotor.m4a',
	'assets/vibemotor.m4a',
	'assets/vibemotor.m4a'
]; 
var loadedSound = {};

$(document).ready(function(){
	init();

	
});


function init(){
	console.log('init')
	// preload();

	window.addEventListener('deviceorientation', handleOrientation);
	// window.addEventListener("resize" , checkWidth);
}



function preload() {
	console.log('preload')
	for (var i = 0; i < soundsArray.length; i++){
		loadedSound[i] = loadSound(soundsArray[i]);
	}
  
}
function setup() {
  
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
		playSounds();
	}
	if (gamma < preveriousGamma - buffer){
		preveriousGamma = gamma ;
		playSounds();

	}
  // Do stuff with the new orientation data
}

function playSounds(){
	loadSound[1].setVolume(0.5);
	loadSound[1].play();
}
