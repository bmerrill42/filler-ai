WINCOUNTER=0
for players in players/*; do
    for maps in maps/*; do
        for i in 1 2 3 4 5; do
            echo $maps
            echo $players
            ./filler_vm -f $maps -p2 $players -p1 players/filler | ./graphics.butts
            x=$( cat filler.trace | grep "won" )
            if [ "$x" == "players/filler won" ]; then
                echo "\x1B[32mFiller Won\x1B[0m"
                let WINCOUNTER=WINCOUNTER+1
                sleep 1
            else
                echo "\033[31mFiller lost\x1B[0m"
                sleep 1
            fi
            ./filler_vm -f $maps -p1 $players -p2 players/filler | ./graphics.butts
            x=$( cat filler.trace | grep "won" )
            if [ "$x" == "players/filler won" ]; then
                echo "\x1B[32mFiller Won\x1B[0m"
                let WINCOUNTER=WINCOUNTER+1
                sleep 1
            else
                echo "\033[31mFiller lost\x1B[0m"
                sleep 1
            fi
        done
        if [ $WINCOUNTER -ge 5 ]; then
            echo '\x1B[32mfiller won the bout against ' $players 'on ' $maps '\x1B[0m'
            sleep 2
        else
            echo '\033[31mfiller lost the bout against ' $players 'on ' $maps '\x1B[0m'
        fi
        let WINCOUNTER=0
    done
done
