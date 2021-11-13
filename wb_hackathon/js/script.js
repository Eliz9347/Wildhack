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

  jQuery(list_element).each(function() {
    var link_on_li = this;
    var link_on_tag = this.children;
    // показ блока и описания тега
    $(link_on_tag).mouseover(function() {
      var attr = $(link_on_li).attr("data-tooltip"); // копируем содержимое data-tooltip. Если ничего нет (или не сущ-т) - undefined
      if(attr) {
        $(".show-descr").css('left', $(link_on_li).offset().left);
        $(".show-descr").css('top', $(link_on_li).offset().top + 25);
        $(".show-descr").css('opacity',  1);
        $(".show-descr").html($(link_on_li).attr('data-tooltip'));
      };
    });
    // сокрытие блока описания при уведении мышки от тега
    $(link_on_tag).mouseout(function(){
      $(".show-descr").css('opacity',  0);
    });
  });

  // работа слайдера
  $('.single-item').slick({
     variableWidth: true,
     infinite: true,
     dots: false,
     slidesToShow: 1,
     slidesToScroll: 1,
     prevArrow: "<img src='./img/vector-left.png' alt='left-arrow' class='prev'>",
     nextArrow: "<img src='./img/vector-right.png' alt='right-arrow' class='next'>",
   });


});
