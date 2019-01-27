__PAL="1"

function color()
{
  echo -e " \e[$__PAL;$2m$1\e[0m"
}

function echored()
{
    echo $(color "$1" "31")
}

function echoblue()
{
    echo $(color "$1" "34")
}

function echogreen()
{
    echo $(color "$1" "32")
}

make > /dev/null
SECONDS=0
./profondeur/solver $1
duration1=$SECONDS
v1=$(echogreen "
depth solver lasted $(($duration1)) seconds on maze $1
")
echo "
$v1
"
SECONDS=0
./largeur/solver $1
duration2=$SECONDS
v2=$(echoblue "
width solver lasted $(($duration2)) seconds on maze $1
")
echo "
$v2
"
SECONDS=0
./astar/solver $1
duration3=$SECONDS
v3=$(echored "
astar solver lasted $(($duration3)) seconds on maze $1")
echo "
$v3"
