ifconfig | grep -w ether | tr -d '\t' | tr -d ' ' | sed 's/ether//'
