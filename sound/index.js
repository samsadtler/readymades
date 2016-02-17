
var preveriousGamma = 0;
var soundsArray = [
	'assets/vibemotor.m4a',
	'assets/child-laughing.wav',
	'assets/man-scream.wav',
	'assets/vibemotor.m4a'
]; 
var loadedSound = [];

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
	 
	 // loadedSound.push(array)
	console.log('preload')
	for (var i = 0; i < soundsArray.length; i++){
		loadedSound.push(loadSound(soundsArray[i]));
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
	
 	
 	if (gamma > preveriousGamma + buffer){	
 		console.log('absolute: ', absolute, ' alpha: ', alpha, ' beta: ', beta, 'gamma: ', gamma)
 		preveriousGamma = gamma;
		playSounds(2);
	}
	if (gamma < preveriousGamma - buffer){
		console.log('absolute: ', absolute, ' alpha: ', alpha, ' beta: ', beta, 'gamma: ', gamma)
		preveriousGamma = gamma ;
		playSounds(1);

	}
  // Do stuff with the new orientation data
}

function playSounds(sound){
	console.log('playSounds')
	loadedSound[sound].setVolume(0.5);
	loadedSound[sound].play();
}
