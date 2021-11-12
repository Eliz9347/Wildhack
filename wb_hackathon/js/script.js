$(document).ready(function() {

  var list_element = jQuery('.tags__list li');

  jQuery(list_element).each(function() {
    var tooltip_info = jQuery(this).attr('data-tooltip');
    if(tooltip_info) {
      var el = jQuery("#list_element", this);
      $(el).addClass('add-dots');
    }
    else {
      $(this).removeAttr('data-tooltip'); // удаление атр. всплывающих подсказок, где их нет
    };
  });

  // изменение цвета кнопки при нажатии
  $('.tags__list-element a').on('click', function() {
    //if($(this).children().html().split(' ').length > 2) {
    $('.display-result').css('display', 'inherit');
    if($(this).parent().attr('type') == 'additional') {
      $(this).parent().toggleClass('clicked-additional');
    }
    else {
      $(this).parent().toggleClass('clicked-main');
    }
    $(this).toggleClass('clicked-main');
    $(this).children().toggleClass('clicked-main');
    if($(this).children().hasClass('add-dots')) {
      $(this).children().toggleClass('clicked-dots');
    };
  });


  // $(element).slick(){
  //
  // };


});
