<?php
$arr = array();
if (empty($arr)){
    printf("The array was seen as empty");
}
else {
    printf("The array was seen as not empty");
}
printf("\n\nhello world! I am in the wdsphp file at www.wash-gop.com and am experimenting on the Swift system (I think)");
echo exec('whoami');
printf("\n\nThat was who apache is running as, I think<br><br>");
phpinfo();

$tstmp = 1441044069;
print ("<br><br>The timestamp is:  " . $tstmp);
print ("<br><br>And the date of that timestamp is:  " . date(' M/d/Y h:i A', $tstmp));
//	This is just  comment.
?>
