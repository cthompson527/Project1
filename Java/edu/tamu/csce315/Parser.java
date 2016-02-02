package edu.tamu.csce315;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Cory Thompson on 1/20/16. <br>
 * This class is designated to read the input file and parse the information to create the Teams.
 */
public class Parser {
    private Scanner scanner;

    /**
     * Constructor. Opens file and prepares for Parsing
     * @param file String name of file to open
     */
    public Parser(String file) {
        try {
            scanner = new Scanner(new File(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * Creates the array of teams by reading in from the file
     * @return ArrayList of Teams
     */
    public ArrayList<Team> createTeams() {
        ArrayList<Team> teams = new ArrayList<>();
        while (scanner.hasNext()) {
            teams.add(createTeam());
        }
        return teams;
    }

    /**
     * Private function to create one team by reading in one line of the file
     * @return Team
     */
    private Team createTeam() {
        String name = scanner.next();
        int asm     = scanner.nextInt();
        double pya  = scanner.nextDouble();
        double dpya = scanner.nextDouble();
        double rya  = scanner.nextDouble();
        double drya = scanner.nextDouble();
        int to      = scanner.nextInt();
        int dto     = scanner.nextInt();
        int pendif  = scanner.nextInt();
        int rettd   = scanner.nextInt();
        return new Team(name, asm, pya, dpya, rya, drya, to, dto, pendif, rettd);
    }
}
