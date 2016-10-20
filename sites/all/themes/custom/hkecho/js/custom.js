$(document).ready(function () {
        var url = window.location;
		$('.left_sidebar ul li a, .middle_nav .navbar-nav li a').filter(function () {
           return this.href == url;
		})
		.parent().addClass('active');
    });
	

$(document).ready(function(){
	
	$('.nav li a').click(function(){
		var url = $(this).attr("href");
		
		$('.nav a[href="'+url+'"]').parent().addClass('current_page_item');
		
	});
});


	

$(document).ready(function () {
    
    $('a[data-toggle="tab"]').on('show.bs.tab', function (e) {

        var $target = $(e.target);
    
        if ($target.parent().hasClass('disabled')) {
            return false;
        }
    });

    $(".next-step").click(function (e) {

        var $active = $('.wizard .nav-tabs li.active');
        $active.next().removeClass('disabled');
        $active.addClass('sucess_fill');
        nextTab($active);

    });
    $(".prev-step").click(function (e) {

        var $active = $('.wizard .nav-tabs li.active');
		prevTab($active);

    });
});

function nextTab(elem) {
    $(elem).next().find('a[data-toggle="tab"]').click();
}
function prevTab(elem) {
    $(elem).prev().find('a[data-toggle="tab"]').click();
}

