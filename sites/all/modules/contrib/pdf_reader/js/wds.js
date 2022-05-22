/*
 * Special bits to take note of:
 *  - Code is assigned to an object in Drupal.behaviors.
 *  - Code that adds behaviors is wrapped in the 'attach' property.
 *  - Anything that has been attached to should get a new CSS class.
 *  - Run Drupal.attachBehaviors() to attach behaviors to new HTML.
 */
(function ($) {
  Drupal.behaviors.pdf_reader = {
    attach: function (context, settings) {     
    	
    	var iframe = $('iframe#pdf_reader');
			var style = document.createElement('style');
			style.textContent =
  			'body {' +
  				'  box-shadow 0 0 0 40px #b3eeff'  +
  '}' ;
//		iframe.contentDocument.head.appendChild(style); 
    }
  }
})(jQuery);
