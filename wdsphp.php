<?php
printf("\n\nhello world!");
phpinfo(INFO_MODULES);

$tstmp = 1441044069;
print ("<br><br>The timestamp is:  " . $tstmp);
print ("<br><br>And the date of that timestamp is:  " . date(' M/d/Y h:i A', $tstmp));

?>
